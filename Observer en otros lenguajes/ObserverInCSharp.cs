using System;
using System.Collections.Generic;
using System.Threading;

namespace ObserverCSharp
{
    public interface IObserver
    {
        // Receive update from subject
        void Update(ISubject subject);
    }

    public interface ISubject
    {
        // Attach an observer to the subject.
        void Attach(IObserver observer);

        // Detach an observer from the subject.
        void Detach(IObserver observer);

        // Notify all observers about an event.
        void Notify();
    }


    public class Subject : ISubject
    {
        public bool info { get; set; } = true;

        private List<IObserver> _observers = new List<IObserver>();

        public void Attach(IObserver observer)
        {
            Console.WriteLine("Subject: Attached an observer.");
            this._observers.Add(observer);
        }

        public void Detach(IObserver observer)
        {
            this._observers.Remove(observer);
            Console.WriteLine("Subject: Detached an observer.");
        }

        public void Notify()
        {
            Console.WriteLine("Subject: Notifying observers...");
            Console.WriteLine();

            foreach (var observer in _observers)
            {
                observer.Update(this);
            }
        }

        public void infoToSend()
        {
            if (info == true)
            {
                Console.WriteLine("\nI got new Info");
                Console.WriteLine();
                this.Notify();
                info = false;
            }
            else
            {
                this.Notify();
                info = true;
            }
            
        }
    }

    // Concrete Observers

    class TvShow : IObserver
    {
        public void Update(ISubject subject)
        {
            if ((subject as Subject).info == true)
            {
                Console.WriteLine("Publishing new Info.");
            }
            else
            {
                Console.WriteLine("There is no New Info.");
            }
        }
    }

    class Magazine : IObserver
    {
        public void Update(ISubject subject)
        {
            if ((subject as Subject).info == true)
            {
                Console.WriteLine("Publishing new Info.");
            }
            else
            {
                Console.WriteLine("There is no New Info.");
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
           
            var subject = new Subject();
            var magazine = new Magazine();
            subject.Attach(magazine);

            var tvShow = new TvShow();
            subject.Attach(tvShow);

            subject.infoToSend();
            subject.infoToSend();

            subject.Detach(magazine);

            subject.infoToSend();
        }
    }
}